FROM debian

EXPOSE 9987/udp 30033/tcp 10011/tcp
ENV TS3SERVER_LICENSE=accept

WORKDIR /home/ts
RUN apt-get update && \
	apt-get upgrade && \
	apt-get install wget tar lbzip2 -y && \
	wget https://files.teamspeak-services.com/releases/server/3.12.1/teamspeak3-server_linux_amd64-3.12.1.tar.bz2 && \
	tar -xf team*

WORKDIR /home/ts/teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh

#docker build -t ts .
#docker run --rm -p 9987:9987/udp -p 30033:30033/tcp -p 10011:10011/tcp -it ts
