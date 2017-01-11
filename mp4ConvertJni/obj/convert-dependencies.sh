#!/bin/sh
# AUTO-GENERATED FILE, DO NOT EDIT!
if [ -f $1.org ]; then
  sed -e 's!^C:/MinGW_mplayer_120913/MinGW_mplayer/!/!ig;s! C:/MinGW_mplayer_120913/MinGW_mplayer/! /!ig;s!^C:/MinGW_mplayer_120913/MinGW_mplayer!/usr!ig;s! C:/MinGW_mplayer_120913/MinGW_mplayer! /usr!ig;s!^C:/Users/ADMINI~1/AppData/Local/Temp!/tmp!ig;s! C:/Users/ADMINI~1/AppData/Local/Temp! /tmp!ig;s!^c:/mingw!/mingw!ig;s! c:/mingw! /mingw!ig;s!^d:!/d!ig;s! d:! /d!ig;s!^c:!/c!ig;s! c:! /c!ig;' $1.org > $1 && rm -f $1.org
fi
