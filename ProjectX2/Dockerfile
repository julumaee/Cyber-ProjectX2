# Use a base image with Ubuntu, which is similar to the CI environment
FROM ubuntu:latest

#Default directory
WORKDIR /ProjectX


RUN apt-get update && \
    apt-get install -y --no-install-recommends python3 python3-pip git cmake libclang-rt-dev libclang-dev curl clang llvm lcov default-jdk zip golang-go make libcap-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN which clang

RUN curl -L https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 -o /usr/local/bin/bazel && \
    chmod +x /usr/local/bin/bazel

RUN which bazel
RUN bazel --version

RUN git clone https://github.com/asadhasan73/cifuzz && \
    cd cifuzz && \
    make install && \
    cd .. && \
    rm -rf cifuzz

#Provide your repository link below
RUN git clone https://github.com/julumaee/Cyber-ProjectX2.git

WORKDIR /ProjectX/Cyber-ProjectX2/ProjectX2
RUN ls -a

CMD ["sh", "-c", "cifuzz run fuzz_test_1 > /ProjectX/Cyber-ProjectX2/ProjectX2/fuzzing.log 2>&1 && cat /ProjectX/Cyber-ProjectX2/ProjectX2/fuzzing.log"]