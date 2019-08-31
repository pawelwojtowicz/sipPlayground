cmake_minimum_required(VERSION 3.10)
project( sipTest )

add_executable( sipTest sipTestMain.cpp )
target_link_libraries( sipTest
		pjsua2 stdc++ pjsua pjsip-ua pjsip-simple pjsip pjmedia-codec pjmedia pj)

add_executable( sipPlayer CSIPPlayer.cpp CPlayerAccount.cpp CPlaybackCall.cpp sipPlayer.cpp CAudioPlayerWithNotification.cpp)
target_link_libraries( sipPlayer
		pjsua2 stdc++ pjsua pjsip-ua pjsip-simple pjsip pjmedia-codec pjmedia pj)

