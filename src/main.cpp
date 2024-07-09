#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;

void Task1(void *pvParameters);
void Task2(void *pvParameters);

void setup()
{
  Serial.begin(9600);

  xTaskCreate(Task1, "Task1", 64, NULL, 2, &Task1_Handle);
  xTaskCreate(Task2, "Task2", 64, NULL, 1, &Task2_Handle);
}

void loop()
{
}

void Task1(void *pvParameters)
{
  (void)pvParameters;
  int count = 0;
  while(1)
  {
    Serial.println("Task1 is running");
    count++;
    if(count == 4)
    {
      vTaskDelete(Task1_Handle);
    }
    delay(1000);
  }
  vTaskDelete(NULL);
}

void Task2(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    Serial.println("Task2 is running");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  vTaskDelete(NULL);
}