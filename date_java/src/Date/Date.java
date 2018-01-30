package Date;

public class Date {
	private int year;
	private int month;
	private int day;
	private int week;
	
	public Date() {
		
	}
	
	public Date(int year, int month, int day, int week) {
		this.year = year;
		this.month = month;
		this.day = day;
		this.week = week;
	}
	
	int GetYear() {
		return this.year;
	}
	
	int GetMonth() {
		return this.month;
	}
	
	int GetDay() {
		return this.day;
	}
	
	int GetWeek() {
		return this.week;
	}
}