FROM ruby:buster

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install rails yarn sqlite3 nodejs -y
EXPOSE 3000

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD RUN gem install bundler && bundle install --full-index
ONBUILD RUN rake db:create
ONBUILD RUN rake db:schema:load
ONBUILD RUN rake db:seed

ONBUILD CMD rails s

#docker build -t ft-rails:on-build .
#docker build -t ror .
#docker run -p 3000:3000 ror
