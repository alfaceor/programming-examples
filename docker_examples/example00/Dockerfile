FROM ubuntu:bionic

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
	apt-get install -y build-essential git autotools-dev
 
# download doxygen and asciidoctor
RUN apt-get install -y texlive-base texlive-latex-recommended texlive-latex-extra
RUN apt-get install -y asciidoctor doxygen
RUN apt-get install -y texlive-font-utils
RUN apt-get install -y autoconf 
RUN apt-get install -y libtool 
RUN apt-get install -y curl 
RUN apt-get install -y wget 

WORKDIR /programs

#RUN git clone https://github.com/statbiophys/IGoR.git 
#RUN git clone https://github.com/statbiophys/IGoR.git 
#WORKDIR /programs/IGoR 
RUN wget https://github.com/statbiophys/IGoR/releases/download/1.4.0/igor_1.4.0.zip
RUN unzip igor_1.4.0.zip 
WORKDIR /programs/igor_1.4.0
#RUN git checkout 1.4.0

#RUN ./autogen.sh
RUN ./configure && make && make install

ENTRYPOINT ["igor"]
