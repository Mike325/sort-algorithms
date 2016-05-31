FROM ubuntu:14.04 
MAINTAINER Mike <miguel.8a.hdez@gmail.com>

# update 
RUN apt-get update && apt-get upgrade -y && \ 
    apt-get install -y git gcc g++ cmake build-essentials

# clone and move repo
RUN mkdir /home/app && cd /home/app 
#RUN git clone https://github.com/Mike325/sort-algorithms.git
ADD sort-algorithms /home/app

# run cmake script
RUN cd sort-algorithms && cmake sort-algorithms && make

# Clean-up
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
