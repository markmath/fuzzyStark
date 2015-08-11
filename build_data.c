void build_data(int *data, int *timeinfo) {
	int year = timeinfo[1];
	int day = timeinfo[2];
	int hour = timeinfo[3];
	int minute = timeinfo[4];

	//Markers
	data[0] = 2;
	for(int i = 9; i <= 59; i += 10) {
		data[i] = 2;
	}

	//Always zero
	data[10] = 0;
	data[11] = 0;
	data[20] = 0;
	data[21] = 0;
	data[55] = 0;
	data[56] = 0;
	data[57] = 0;
	data[58] = 0;
	for(int i = 4; i <= 54; i += 10) {
		data[i] = 0;
	}
	for(int i = 35; i <= 43; i += 1) {
		if (i != 39) {
			data[i] = 0;
		} 
	}


	//Determine the bits for the minute tens digit
	data[1] = minute >= 40;
	data[2] = (minute % 40) >= 20;
	data[3] = (minute % 20) >= 10;

	//Determine the bits fo the minute ones digit
	int minuteOnes = minute % 10;
	data[5] = minuteOnes >= 8;
	data[6] = (minuteOnes % 8) >= 4;
	data[7] = (minuteOnes % 4) >= 2;
	data[8] = (minuteOnes % 2) >= 1;
	
	//Determine the bits for the hour tens digit
	data[12] = hour >= 20;
	data[13] = (hour % 20) >= 10;
	
	//Determine the bits for the hour ones digit
	int hourOnes = hour % 10;
	data[15] = hourOnes >= 8;
	data[16] = (hourOnes % 8) >= 4;
	data[17] = (hourOnes % 4) >= 2;
	data[18] = (hourOnes % 2) >= 1;
	
	//Determine the day hundreds digit
	data[22] = day >= 200;
	data[23] = (day % 200) >= 100;
	
	//Determine the day tens digit
	int dayTens = day % 100;
	data[25] = dayTens >= 80;
	data[26] = (dayTens % 80) >= 40;
	data[27] = (dayTens % 40) >= 20;
	data[28] = (dayTens % 20) >= 10;
	
	//Determine the day ones digit
	int dayOnes = day % 10;
	data[30] = dayOnes >= 8;
	data[31] = (dayOnes % 8) >= 4;
	data[32] = (dayOnes % 4) >= 2;
	data[33] = (dayOnes % 2) >= 1;
	
	//Determine the year tens digit
	int yearTens = year % 100;
	data[45] = yearTens >= 80;
	data[46] = (yearTens % 80) >= 40;
	data[47] = (yearTens % 40) >= 20;
	data[48] = (yearTens % 20) >= 10;
	
	//Determine the year ones digit
	int yearOnes = yearTens % 10;
	data[50] = yearOnes >= 8;
	data[51] = (yearOnes % 8) >= 4;
	data[52] = (yearOnes % 4) >= 2;
	data[53] = (yearOnes % 2) >= 1;
	
	//Display data
	/*for(i = 0; i < 60; i = i+5) {
		printf("%d	%d	%d	%d	%d", data[i], data[i+1], data[i+2], data[i+3], data[i+4]);
	}*/
	
}
