#!/usr/bin/env bash
cd "$(dirname "$0")" || exit 1

docker run -d \
  -v ./conf.d:/etc/nginx/conf.d:ro \
  -v ./html:/usr/share/nginx/html:ro \
  --network host \
  --name gateway \
  nginx:1.25.1-alpine
