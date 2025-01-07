#define MQ2_AO_PIN A0
#define MQ2_DO_PIN 2
#define FLAME_AO_PIN A1
#define FLAME_DO_PIN 3
#define BUZZER_PIN 4
#define BUTTON_PIN 5
#define YELLOW_LED_PIN 6
#define RED_LED_PIN 7
#define GAS_WARNING_THRESHOLD 300
#define GAS_CRITICAL_THRESHOLD 600

bool alarmActive = false;

void setup() {
    Serial.begin(9600);
    pinMode(MQ2_AO_PIN, INPUT);
    pinMode(MQ2_DO_PIN, INPUT);
    pinMode(FLAME_AO_PIN, INPUT);
    pinMode(FLAME_DO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    int gasAnalogValue = analogRead(MQ2_AO_PIN);
    bool gasCriticalDigital = digitalRead(MQ2_DO_PIN) == LOW;
    int flameAnalogValue = analogRead(FLAME_AO_PIN);
    bool flameCriticalDigital = digitalRead(FLAME_DO_PIN) == LOW;

    Serial.print("Gás: ");
    Serial.print(gasAnalogValue);
    Serial.print(" | Chama: ");
    Serial.println(flameAnalogValue);

    if ((gasAnalogValue > GAS_WARNING_THRESHOLD && gasAnalogValue < GAS_CRITICAL_THRESHOLD) && !alarmActive) {
        digitalWrite(YELLOW_LED_PIN, HIGH);
        tone(BUZZER_PIN, 1000, 100);
        delay(300);
        digitalWrite(YELLOW_LED_PIN, LOW);
    }

    if ((gasCriticalDigital || flameCriticalDigital) && !alarmActive) {
        activateCriticalAlarm();
    }

    if (digitalRead(BUTTON_PIN) == LOW && alarmActive) {
        deactivateAlarm();
    }

    delay(500);
}

void activateCriticalAlarm() {
    alarmActive = true;
    Serial.println("ALERTA CRÍTICO ATIVADO!");
    while (alarmActive) {
        digitalWrite(RED_LED_PIN, HIGH);
        tone(BUZZER_PIN, 1000);
        delay(500);
        digitalWrite(RED_LED_PIN, LOW);
        delay(500);

        if (digitalRead(BUTTON_PIN) == LOW) {
            deactivateAlarm();
        }
    }
}

void deactivateAlarm() {
    alarmActive = false;
    noTone(BUZZER_PIN);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    Serial.println("Alarme Desativado!");
}
