package DC;
import java.lang.Object;
interface Template<T,E> {
	public void train();
	public void load(T M);
	public Object searching(E point);
}
