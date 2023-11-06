FROM alpine

RUN apk add git bash make gcc clang musl-dev

ADD . /Workspace/strbuff

WORKDIR /Workspace/strbuff

RUN git submodule init && git submodule update

