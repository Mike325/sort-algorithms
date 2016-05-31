FROM ubuntu:14.04

RUN apt-get update && apt-get -y upgrade 
RUN apt-get -y install build-essential cmake gcc g++ git 

RUN echo foo > bar
