# ABSTRACT
#### In this project we focus on automating Heater so, we need not to trigger it manually daily morning rather it will get ON and heat water according to environement temperature. Environement temperature is considered here because in summer season we need not want water to be too hot but in winter season we need hotter water. So depending on place and season we decide how much our water needs to be hot. If we heat water for less time its temperature will be less than when heat it for long time. So we sense temperature with LM35 temperature sensor and control heater with relay. When and how much time relay is closed is controlled by Atmega 328p which takes Temperature sensor value and accordingly controls Relay. Also there is a option to switch it manually to avoid this automation. This is programmed in multifile programming format and simulated in simulides. CI/CD is also implemented with build and Static analysis.

## 4W's 1H
##### WHY? To save time needed to wait for water to get heated everyday morning.
##### WHEN? EVERYDAY it is needed.
##### WHAT? Automation.
##### WHERE? Rrsidential areas.
##### HOW? With MCU and sensor.
## SWOT
|STRENGTH|WEAKNESS|OPPERTUNITY|THREATS|
|:--:|:--:|:--:|:--:|
|Automation|Does not take Humidity into account|Can add Humidity sensor|MCU needs to run for long time so need to adapt some power saving techniques
## HLR
|ID|DESCRIPTION|
|:--:|:--:|
|1|Automate existing heater
## LLR
|HLR|LLR||
|:--:|:--:|:--:|
|1|MCU,RELAY,SENSOR|Atemga328p,Relay,LM35

## COMPONENTS
Relay - to close the circuit between source and heater controlled by Atmega 328 as we cannot power heater with MCU
Atmega 328 - To process Sensor data and control Relay accordingly
LM35 - Temperature sensor output voltage is proportional to Temperature
## SIMULATION
- Since LM35 is not available we use a potentiometer to mimic anlog signals from LM35
- In reality timer need to count hours for easy of simulation time 1min represents 23hrs and 30s,15s represents 20min, 10min respectively

## FLOWDIAGRAM
![](https://github.com/Saishivasai/M2_Automaticheater/blob/master/2_Design/img/1.png)

## TESTCASES
|TEMPERATURE|EXPECTED HEATER ON TIME|OBSERVED RESULT|
|:--:|:--:|:--:|
|20-30 degree celcius|30s|30s
|30-50 degree celcius|15S|15s

## OUTPUT
![](https://github.com/Saishivasai/M2_Automaticheater/blob/master/6_Output/img/2.png)

