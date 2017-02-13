package com.musala.trainings;

public class NumbersUtil {
	
	public static int[] maxEquals(int[] numbers) {
		int maxlength = 1;
		int start = 0;
		int length = 1;
		int index = 0;
		for (int i = 1; i < numbers.length; i++) {
			while (i < numbers.length && numbers[i] == numbers[i - 1]) {
				length++;
				i++;
			}
			if (maxlength < length) {
				maxlength = length;
				start = index;
			}
			length = 1;
			index = i;
		}
		
		int[] result = new int[maxlength];
		
		for (int i = start; i < start + maxlength; i++) {
			result[i - start] = numbers[i];
		}
		
		return result;
	}
}
