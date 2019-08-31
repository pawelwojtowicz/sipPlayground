#include "CPlayerAccount.h"
#include <iostream>

namespace SIPPlayer
{

CPlayerAccount::CPlayerAccount()
{
}

CPlayerAccount::~CPlayerAccount()
{
}

void CPlayerAccount::onRegState(pj::OnRegStateParam &prm)
{
  pj::AccountInfo ai = getInfo();
  std::cout << (ai.regIsActive? "*** Register:" : "*** Unregister:") << " code=" << prm.code << std::endl;

  if ( ai.regIsActive ) 
  {
  }


}

void CPlayerAccount::onIncomingCall(pj::OnIncomingCallParam &iprm)
{
}


}
