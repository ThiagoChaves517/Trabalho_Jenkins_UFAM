// Define um pacote para organização (boa prática)
package main;

public class ConversaoTemperatura {

    /**
     * Converte uma temperatura de Fahrenheit (F) para Celsius (C).
     * Fórmula: C = (F - 32) * 5/9
     * @param fahrenheit Temperatura em graus Fahrenheit.
     * @return Temperatura em graus Celsius.
     */
    public static double fahrenheitParaCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5.0 / 9.0;
    }

    /**
     * Converte uma temperatura de Celsius (C) para Fahrenheit (F).
     * Fórmula: F = C * 9/5 + 32
     * @param celsius Temperatura em graus Celsius.
     * @return Temperatura em graus Fahrenheit.
     */
    public static double celsiusParaFahrenheit(double celsius) {
        return (celsius * 9.0 / 5.0) + 32;
    }
}
