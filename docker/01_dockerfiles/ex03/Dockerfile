FROM ruby:2.6.6-buster
RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install build-essential cmake libre2-5 libre2-dev rails yarn sqlite3 nodejs git -y

RUN gem install bundler

RUN git clone https://gitlab.com/gitlab-org/gitlab-foss.git opt/gitlab
WORKDIR /opt/gitlab

RUN mv config/database.yml.postgresql config/database.yml

RUN gem install re2 && bundle update --bundler && bundle install --full-index

EXPOSE 3000
RUN rails s
