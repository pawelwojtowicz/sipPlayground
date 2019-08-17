#include <pjsua2.hpp>
#include <iostream>

using namespace pj;

class MyCall : public Call
{
public:
    MyCall(Account &acc, int call_id = PJSUA_INVALID_ID)
    : Call(acc, call_id)
    { }

    ~MyCall()
    { }

    // Notification when call's state has changed.
    virtual void onCallState(OnCallStateParam &prm)
    {
    }

    // Notification when call's media state has changed.
    virtual void onCallMediaState(OnCallMediaStateParam &prm)
    {
      CallInfo ci = getInfo();
      // Iterate all the call medias
      for (unsigned i = 0; i < ci.media.size(); i++) {
          if (ci.media[i].type==PJMEDIA_TYPE_AUDIO && getMedia(i)) {
              AudioMedia *aud_med = (AudioMedia *)getMedia(i);

              // Connect the call audio media to sound device
              AudDevManager& mgr = Endpoint::instance().audDevManager();
              aud_med->startTransmit(mgr.getPlaybackDevMedia());
              mgr.getCaptureDevMedia().startTransmit(*aud_med);
          }
      }
    }
};


// Subclass to extend the Account and get notifications etc.
class MyAccount : public Account {
public:
    virtual void onRegState(OnRegStateParam &prm) {
        AccountInfo ai = getInfo();
        std::cout << (ai.regIsActive? "*** Register:" : "*** Unregister:")
                  << " code=" << prm.code << std::endl;
    }

    void onIncomingCall(OnIncomingCallParam &iprm)
    {
        Call *call = new MyCall(*this, iprm.callId);
        CallOpParam prm;
        prm.statusCode = PJSIP_SC_OK;
        call->answer(prm);
    }
};

int main(int argc, char** argv)
{
  Endpoint ep;

  ep.libCreate();

  // Initialize endpoint
  EpConfig ep_cfg;
  ep.libInit( ep_cfg );

 // Create SIP transport. Error handling sample is shown
    TransportConfig tcfg;
    tcfg.port = 5061;
    try {
        ep.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);
    } catch (Error &err) {
        std::cout << err.info() << std::endl;
        return 1;
    }


    // Start the library (worker threads etc)
    ep.libStart();
    std::cout << "*** PJSUA2 STARTED ***" << std::endl;

    // Configure an AccountConfig
    AccountConfig acfg;
    acfg.idUri = "sip:5001@localhost";
    acfg.regConfig.registrarUri = "sip:localhost";
    AuthCredInfo cred("asterisk", "*", "5001", 0, "pawel");
    acfg.sipConfig.authCreds.push_back( cred );

    // Create the account
    MyAccount *acc = new MyAccount;
    acc->create(acfg);

    // Here we don't have anything else to do..
    pj_thread_sleep(60000);

    // Delete the account. This will unregister from server
    delete acc;
  return 0;
}


