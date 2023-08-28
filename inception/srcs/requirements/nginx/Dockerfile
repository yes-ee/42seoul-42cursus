FROM debian:bullseye

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y dumb-init nginx openssl

RUN mkdir -p /etc/ssl
    
COPY conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./tools/setting.sh /setting.sh

RUN chmod +x setting.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "/setting.sh"]
