FROM ruby:buster
RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install rails yarn sqlite3 nodejs git -y

RUN gem install bundler

RUN git clone https://gitlab.com/gitlab-org/gitlab-foss.git opt/gitlab
WORKDIR /opt/gitlab

RUN bundle update --bundler && bundle install --full-index

EXPOSE 3000

RUN /bin/sh
