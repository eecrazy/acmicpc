// BEGIN CUT HERE
PROBLEM STATEMENT
This week there will be an important meeting of your entire department. You clearly remember your boss telling you about it. The only thing you forgot is the day of the week when the meeting will take place.

You asked six of your colleagues about the meeting. None of them knew the day when it will take place, but each of them remembered one day when it will not take place. The days they remembered were distinct. For a clever programmer like you, this was enough to determine the day of the meeting.

You are given a String[] notOnThisDay containing six weekdays when the meeting will not take place. Return the weekday of the meeting.

DEFINITION
Class:WhichDay
Method:getDay
Parameters:String[]
Returns:String
Method signature:String getDay(String[] notOnThisDay)


NOTES
-There are seven weekdays. Their names are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday".


CONSTRAINTS
-notOnThisDay will contain exactly 6 elements.
-Each element of notOnThisDay will be a name of a weekday (in the exact form specified in the Note above).
-No two elements of notOnThisDay will be equal.


EXAMPLES

0)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}

Returns: "Saturday"



1)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}

Returns: "Saturday"



2)
{"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}

Returns: "Wednesday"



3)
{"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}

Returns: "Thursday"



// END CUT HERE
import java.util.*;
public class WhichDay 
{
	public String getDay(String[] notOnThisDay) 
	{
		
	}

	public static void main(String[] args) 
	{
		WhichDay temp = new WhichDay();
		System.out.println(temp.getDay(String[] notOnThisDay));
	}
}
