/*算法 

4-2-2 00:00::00 - offsetdays 00:00:00

source time
year
month
day
hour
minute
second

offsetdays time

days
hour
minute
second

1.cal time  
resultsecond-
resultminute-
resulthour-

2.*************
cal the new year the new month the new days

		0<day<365
		365<day<365*3+366 未必包含闰年  考虑year 和上一个最近的闰年之间的距离
		day>365*3+366 一定包含闰年，计算拥有4年的周期，有m个闰年，p个平年 然后先得到year
		//得到year之后，对月份和day进行微调，offsetdays-n*T 剩下的天，计算月份和day即可 
*/
