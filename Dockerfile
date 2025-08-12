FROM debian:bookworm

WORKDIR /inventory

RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    valgrind \
    git \
    && apt-get clean && rm -rf /var/lib/apt/lists/*