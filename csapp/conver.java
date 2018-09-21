import java.text.NumberFormat;
 public class Main {
	private static final String[] NUM_CHINESE_COMPLEX = { "零", "壹", "貳", "叁", "肆", "伍", "陸", "柒", "捌", "玖" };
	private static final String[] UNIT_CHINESE_COMPLEX = { "", "拾", "佰", "仟", "萬", "億" };

	private static String doubleToRMBString(Double doubleparam){
		if (doubleparam == null )
			return null;
		NumberFormat nf = NumberFormat.getInstance();
		nf.setGroupingUsed(false);
		String sDouble = nf.format(doubleparam);
		String result;
		if (sDouble.indexOf('.')>0 && (sDouble.indexOf('.')==sDouble.lastIndexOf('.'))) {
			String[] array = sDouble.split("\\.");
			result = intToRMBString(Long.valueOf(array[0]))+"点"+decimalToRMBString(array[1]);
		}else {
			result = intToRMBString(Long.valueOf(sDouble));
		}
		if (result.endsWith("点")) {
			result = result.substring(0, result.length()-1);
		}
		return result;
	}
	
	private static String intToRMBString(Long longparam){
		String sInteger = longparam.toString();
		int length = sInteger.length();
		String result ; 
		if (length > 0 && length < 6) {
			result = getChinese(sInteger);
		}else if (length >= 6 && length < 9) {
			result = getChinese(sInteger.substring(0,length-4)).concat("萬").concat(getChinese(sInteger.substring(length-4)));
		}else if (length >= 9 && length < 14){
			result =getChinese(sInteger.substring(0,length-8))+"億" + getChinese(sInteger.substring(length-8,length-4)).concat("萬").concat(getChinese(sInteger.substring(length-4)));
		}else {
			String temp = sInteger.substring(0,length-8);
			String aa = intToRMBString(Long.valueOf(temp));
			result = aa +"億" + getChinese(sInteger.substring(length-8,length-4)).concat("萬").concat(getChinese(sInteger.substring(length-4)));
		}
		return result;
	}

	private static String getChinese(String ss) {
		StringBuffer sb = new StringBuffer();
		boolean flag = true;
		for (int i = 0 ,j = ss.length(); i < j; i++) {
			int index = ss.charAt(i) - '0';
			String temp = NUM_CHINESE_COMPLEX[index];
			String unitTemp = UNIT_CHINESE_COMPLEX[j - i - 1];
			if (index == 0 && flag == true) {
				sb.append(temp);
				flag = false;
			}
			if (index != 0) {
				sb.append(temp).append(unitTemp);
			}
		}
		if (sb.toString().endsWith("零")) {
			return sb.toString().substring(0,sb.toString().length()-1);
		}
		return sb.toString();
	}

	private static String decimalToRMBString(String ss) {
		StringBuffer sb = new StringBuffer();
		for (int i = 0,j=ss.length(); i < j; i++) {
			sb.append(NUM_CHINESE_COMPLEX[Character.getNumericValue(ss.charAt(i))]);
		}
		return sb.toString();
	}
	public static void main(String[] args) {
		System.out.println(doubleToRMBString(25.2600));
	}
}
