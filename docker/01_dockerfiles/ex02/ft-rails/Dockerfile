FROM ruby:buster
RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install rails yarn sqlite3 nodejs -y

COPY app /opt/app
WORKDIR /opt/app
RUN gem install bundler && bundle install --full-index
RUN rails webpacker:install

EXPOSE 3000

CMD rails s
