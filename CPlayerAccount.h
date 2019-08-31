#pragma once
#include <pjsua2.hpp>

namespace SIPPlayer
{

class CPlayerAccount : public pj::Account 
{
public:
  CPlayerAccount();
  virtual ~CPlayerAccount();
	
  virtual void onRegState(pj::OnRegStateParam &prm) override;

  virtual void onIncomingCall(pj::OnIncomingCallParam &iprm) override;
};

}

