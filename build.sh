#!/bin/bash

VERSION="1.0.7"

mkdir -p ./build/
mkdir -p ./build/libnmpp_${VERSION}_amd64/
mkdir -p ./build/libnmpp_${VERSION}_amd64/DEBIAN/
mkdir -p ./build/libnmpp_${VERSION}_amd64/usr/
mkdir -p ./build/libnmpp_${VERSION}_amd64/usr/include/
mkdir -p ./build/libnmpp_${VERSION}_amd64/usr/include/NMPP/
mkdir -p ./build/libnmpp_${VERSION}_amd64/usr/lib/
mkdir -p ./build/libnmpp_${VERSION}_amd64/usr/lib/x86_64-linux-gnu/

rm -rf ./build/libnmpp_${VERSION}_amd64/usr/include/NMPP/*
rm -rf ./build/libnmpp_${VERSION}_amd64/usr/lib/x86_64-linux-gnu/*

cp -r ./debian/DEBIAN/* ./build/libnmpp_${VERSION}_amd64/DEBIAN/
cmake -L .
make -j4
cp -r -d ./objects/libNMPP.so* ./build/libnmpp_${VERSION}_amd64/usr/lib/x86_64-linux-gnu/
cp -r -d ./header/* ./build/libnmpp_${VERSION}_amd64/usr/include/NMPP/

dpkg-deb --build ./build/libnmpp_${VERSION}_amd64
