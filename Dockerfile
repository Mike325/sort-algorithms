FROM alpine
MAINTAINER Mike <miguel.8a.hdez@gmail.com>

# updateKyle Manna 
RUN echo "http://dl-4.alpinelinux.org/alpine/edge/community/" >> /etc/apk/repositories && \
    echo "http://dl-4.alpinelinux.org/alpine/edge/testing/" >> /etc/apk/repositories && \
    apk add --update bash build-base gcc abuild binutils cmake extra-cmake-modules 

# clone and move repo
RUN git clone https://github.com/Mike325/sort-algorithms.git
RUN mkdir /home/sort-algorithms && cp -R sort-algorithms/ /home/sort-algorithms

# run cmake script
RUN cd /home/sort-algorithms && cmake sort-algorithms && make

# Clean-up
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
