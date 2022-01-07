FROM ubuntu:focal

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
        apt-get install -y build-essential git autotools-dev

# download doxygen and asciidoctor
RUN apt-get install -y texlive-base texlive-latex-recommended texlive-latex-extra
RUN apt-get install -y asciidoctor doxygen
RUN apt-get install -y texlive-font-utils
RUN apt-get install -y autoconf
RUN apt-get install -y libtool

WORKDIR /programs

RUN git clone https://github.com/statbiophys/IGoR.git
WORKDIR /programs/IGoR

RUN ./autogen.sh
RUN ./configure && make && make install

WORKDIR /programs
RUN git clone https://github.com/statbiophys/pygor3.git
WORKDIR /programs/pygor3
#RUN pip install -e .

ENTRYPOINT ["igor"]

ENTRYPOINT ["pygor"]


