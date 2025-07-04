package main;

public class TestadorConversao {

    public static void main(String[] args) {
        System.out.println("Iniciando bateria de testes...");
        boolean todosOsTestesPassaram = true;

        // Teste 1: Ponto de congelamento da água (32°F = 0°C)
        double celsiusResult = ConversaoTemperatura.fahrenheitParaCelsius(32);
        if (celsiusResult != 0) {
            System.out.println("FALHA: Teste 1 - 32°F para Celsius. Esperado: 0. Recebido: " + celsiusResult);
            todosOsTestesPassaram = false;
        } else {
            System.out.println("SUCESSO: Teste 1 - 32°F para 0°C.");
        }

        // Teste 2: Ponto de ebulição da água (100°C = 212°F)
        double fahrenheitResult = ConversaoTemperatura.celsiusParaFahrenheit(100);
        if (fahrenheitResult != 212) {
            System.out.println("FALHA: Teste 2 - 100°C para Fahrenheit. Esperado: 212. Recebido: " + fahrenheitResult);
            todosOsTestesPassaram = false;
        } else {
            System.out.println("SUCESSO: Teste 2 - 100°C para 212°F.");
        }

        // Teste 3 (adicional): Temperatura corporal (98.6°F = 37°C)
        // Usamos uma pequena margem de erro para comparações de ponto flutuante
        double celsiusResult2 = ConversaoTemperatura.fahrenheitParaCelsius(98.6);
        if (Math.abs(celsiusResult2 - 37) > 0.001) {
            System.out.println("FALHA: Teste 3 - 98.6°F para Celsius. Esperado: 37. Recebido: " + celsiusResult2);
            todosOsTestesPassaram = false;
        } else {
            System.out.println("SUCESSO: Teste 3 - 98.6°F para 37°C.");
        }

        System.out.println("\n--- Resultado Final ---");
        if (!todosOsTestesPassaram) {
            System.out.println(">> ALGUNS TESTES FALHARAM! <<");
            // Sai com um código de erro, o que fará o build do Jenkins falhar!
            System.exit(1);
        } else {
            System.out.println(">> TODOS OS TESTES PASSARAM COM SUCESSO! <<");
            // Sai com código de sucesso
            System.exit(0);
        }
    }
}
