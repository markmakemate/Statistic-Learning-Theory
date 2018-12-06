package DC;
import DC.Template;
import java.lang.Object;
public class Implement<T,E> implements Template<T,E> {
	private T classifier;
	public void run() {
		classifier.training();
	}
	public void load(T M) {
		classifier=M;
	}
	public Object searching(E point) {
		return classifier.searching(point);
	}
}


