public class TextEdit
{

	// Methods
	public Type GetType() {}
	public virtual string ToString() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public VisualStyleElement Normal { get{} }
	public VisualStyleElement Hot { get{} }
	public VisualStyleElement Selected { get{} }
	public VisualStyleElement Disabled { get{} }
	public VisualStyleElement Focused { get{} }
	public VisualStyleElement ReadOnly { get{} }
	public VisualStyleElement Assist { get{} }
}

