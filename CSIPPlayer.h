#pragma once
#include <pjsua2.hpp>

namespace SIPPlayer
{

class CSIPPlayer
{
public:
  CSIPPlayer();
  virtual ~CSIPPlayer();

protected:
public:
  bool Initialize( const std::string sipServer, const std::string& user, const std::string& password );

  void Shutdown();

  void PlayWAV( const std::string& waveFilename );

private:
  pj::Endpoint m_sipEndpoint;

  pj::Account* m_pPlayerAccount;

  std::string m_remoteSpeakerURI;
  
};

}
