# Dockerfile

# Use uma imagem base do OpenJDK para compilar nosso código
FROM openjdk:17-jdk-slim

# Define o diretório de trabalho dentro do contêiner
WORKDIR /app

# Copia todo o código-fonte do nosso projeto para o diretório de trabalho no contêiner
COPY src/ .

# Compila os arquivos .java, agora com os caminhos corretos
RUN javac -d . main/ConversaoTemperatura.java test/TestadorConversao.java