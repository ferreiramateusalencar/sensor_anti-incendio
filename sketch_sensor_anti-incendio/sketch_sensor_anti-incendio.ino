#define MQ2_AO_PIN A0  // Pino analógico do sensor MQ-2 para leitura de valores de gás
#define MQ2_DO_PIN 2   // Pino digital do sensor MQ-2 para detecção crítica
#define FLAME_AO_PIN A1  // Pino analógico do sensor de chama
#define FLAME_DO_PIN 3   // Pino digital do sensor de chama para detecção crítica
#define BUZZER_PIN 4     // Pino do buzzer passivo
#define BUTTON_PIN 5     // Pino do botão de reset
#define YELLOW_LED_PIN 6 // LED amarelo para alertas leves
#define RED_LED_PIN 7    // LED vermelho para alertas críticos
#define GAS_WARNING_THRESHOLD 300   // Limite de aviso para gás
#define GAS_CRITICAL_THRESHOLD 600  // Limite crítico de gás

bool alarmActive = false;  // Variável para controlar o estado do alarme

void setup() {
    Serial.begin(9600);  // Inicializa a comunicação serial
    
    // Configuração dos pinos de entrada e saída
    pinMode(MQ2_AO_PIN, INPUT);
    pinMode(MQ2_DO_PIN, INPUT);
    pinMode(FLAME_AO_PIN, INPUT);
    pinMode(FLAME_DO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Ativa o resistor interno do botão
}

void loop() {
    // Leitura dos sensores
    int gasAnalogValue = analogRead(MQ2_AO_PIN);
    bool gasCriticalDigital = digitalRead(MQ2_DO_PIN) == LOW;
    int flameAnalogValue = analogRead(FLAME_AO_PIN);
    bool flameCriticalDigital = digitalRead(FLAME_DO_PIN) == LOW;

    // Exibir valores lidos no monitor serial
    Serial.print("Gás: ");
    Serial.print(gasAnalogValue);
    Serial.print(" | Chama: ");
    Serial.println(flameAnalogValue);

    // Alerta leve para níveis moderados de gás
    if ((gasAnalogValue > GAS_WARNING_THRESHOLD && gasAnalogValue < GAS_CRITICAL_THRESHOLD) && !alarmActive) {
        digitalWrite(YELLOW_LED_PIN, HIGH);
        tone(BUZZER_PIN, 1000, 100);  // Buzzer curto
        delay(300);
        digitalWrite(YELLOW_LED_PIN, LOW);
    }

    // Alerta crítico (gás muito alto ou chama detectada)
    if ((gasCriticalDigital || flameCriticalDigital) && !alarmActive) {
        activateCriticalAlarm();
    }

    // Resetar o alarme pelo botão
    if (digitalRead(BUTTON_PIN) == LOW && alarmActive) {
        deactivateAlarm();
    }

    delay(500);  // Intervalo de leitura dos sensores
}

// Função para ativar o alarme crítico
void activateCriticalAlarm() {
    alarmActive = true;
    Serial.println("ALERTA CRÍTICO ATIVADO!");
    while (alarmActive) {
        digitalWrite(RED_LED_PIN, HIGH);
        tone(BUZZER_PIN, 1000);  // Alerta sonoro contínuo
        delay(500);
        digitalWrite(RED_LED_PIN, LOW);
        delay(500);

        // Desligar o alarme ao pressionar o botão
        if (digitalRead(BUTTON_PIN) == LOW) {
            deactivateAlarm();
        }
    }
}

// Função para desativar o alarme
void deactivateAlarm() {
    alarmActive = false;
    noTone(BUZZER_PIN);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    Serial.println("Alarme Desativado!");
}
