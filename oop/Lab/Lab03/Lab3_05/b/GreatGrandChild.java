package b;

public class GreatGrandChild extends GrandChild {
	//是GrandChild同一个包的子类
	//可以调用public，protected
	//不可以调用private，void
	public static void main(String[] args){
		GreatGrandChild g = new GreatGrandChild();
		//g.cm1();
		//g.cm2();
		g.cm3();
		g.cm4();
		//g.fm1();
		//g.fm2();
		g.fm3();
		g.fm4();
    }
}
