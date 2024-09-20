# Use a base image with Ubuntu, which is similar to the CI environment
FROM ubuntu:latest

#Default directory
WORKDIR /ProjectX2-main


RUN apt-get update && \
    apt-get install -y --no-install-recommends python3 git curl clang llvm lcov default-jdk zip golang-go make && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN which clang

RUN curl -L https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 -o /usr/local/bin/bazel && \
    chmod +x /usr/local/bin/bazel

RUN which bazel
RUN bazel --version

#RUN sh -c "$(curl -fsSL https://github.com/asadhasan73/cifuzz/blob/main/install.sh)"
#RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/CodeIntelligenceTesting/cifuzz/main/install.sh)"


# Install cifuzz

RUN git clone https://github.com/asadhasan73/cifuzz
RUN cd cifuzz
RUN make install
RUN ..

#Provide your repository link below
RUN git clone https://github.com/julumaee/Cyber-ProjectX2.git

WORKDIR /ProjectX2-main
RUN ls -a

RUN cifuzz --version  # Verify cifuzz installation

CMD ["sh", "-c", "cifuzz run test:test --use-sandbox=false > /ProjectX2-main/fuzzing.log 2>&1 && cat /ProjectX/ProjectX2/fuzzing.log"]
