pipeline {
    agent any
    
    triggers {
        // Executa de segunda a sexta às 23:05
        cron('5 23 * * 1-5') 
    }

    stages {
        stage('Checkout') {
            steps {
                echo 'Código baixado do GitHub com sucesso.'
            }
        }

        stage('Build') {
            steps {
                script {
                    echo 'Construindo a imagem Docker para build e teste...'
                    def imageName = "conversao-app:${BUILD_NUMBER}"
                    docker.build(imageName, '.')
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    echo 'Executando os testes em um novo contêiner...'
                    def imageName = "conversao-app:${BUILD_NUMBER}"
                    
                    // Adicionado o --rm para que o contêiner seja removido automaticamente
                    sh "docker run --rm ${imageName} java main.TestadorConversao"
                }
            }
        }
    }

    post {
        always {
            echo 'Limpando a imagem Docker do build...'
            script {
                def imageName = "conversao-app:${BUILD_NUMBER}"
                sh "docker rmi ${imageName} || true"
            }
        }
    }
}
