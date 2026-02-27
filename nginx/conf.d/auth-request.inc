location = /_auth_request {
    internal;
    proxy_pass          http://127.0.0.1:3500/api/protected;
    proxy_set_header    Host auth.nano-exp.com;
    proxy_set_header    X-Real-IP $remote_addr;
    proxy_set_header    X-Forwarded-For $proxy_add_x_forwarded_for;
    proxy_set_header    X-Forwarded-Proto $scheme;
    proxy_set_header    X-Original-URI $scheme://$host$request_uri;
}

location @login_redirect {
    return 302 https://auth.nano-exp.com/login?redirect=$scheme://$http_host$request_uri;
}

