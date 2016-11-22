#include <stdio.h>

int main(void) {
  int departureTimeInMin[8] = {
    480, 583, 679, 767, 840, 945, 1140, 1305
  };
  int arriveTimeInMin[8] = {
    616, 712, 811, 900, 968, 1075, 1280, 1438
  };
  int enteredHour, enteredMin;
  int enteredTimeInMin;
  int minus1, minus2;
  int closestDepartureTimeInMin;
  int closestDepartureHour,closestDepartureMin;
  int arriveTimeInMin2;
  int arriveHour,arriveMin;
  
  
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &enteredHour, &enteredMin);

  enteredTimeInMin = enteredHour * 60 + enteredMin;

  for (int i = 0; i < 7; i++) {
    minus1 = enteredTimeInMin - departureTimeInMin[i];
    minus2 = departureTimeInMin[i + 1] - enteredTimeInMin;
     if(enteredTimeInMin<480){
    	closestDepartureTimeInMin = departureTimeInMin[0];
       arriveTimeInMin2 = arriveTimeInMin[0];
   }
   if (minus1 < minus2&&minus2>=0&&minus1>=0){
      closestDepartureTimeInMin = departureTimeInMin[i];
      arriveTimeInMin2 = arriveTimeInMin[i];
    } else if (minus2 >=0&&minus1>=0){
      closestDepartureTimeInMin = departureTimeInMin[i+1];
      arriveTimeInMin2 = arriveTimeInMin[i+1];
      } 
  }
  closestDepartureMin = closestDepartureTimeInMin % 60;
  
  closestDepartureHour = (closestDepartureTimeInMin -closestDepartureMin)/60;
  closestDepartureHour = closestDepartureHour > 12 ? closestDepartureHour -12:closestDepartureHour;
  arriveMin = arriveTimeInMin2 %60;
  arriveHour = (arriveTimeInMin2 - arriveMin) /60;
  arriveHour = arriveHour >12 ? arriveHour - 12:arriveHour;
  printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.",closestDepartureHour,closestDepartureMin,closestDepartureTimeInMin > 720? 'p':'a',arriveHour,arriveMin,arriveTimeInMin2 > 720?'p':'a');
  
  return 0;
}
       