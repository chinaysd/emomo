public class InitializationEventAttribute : System.Attribute, System.Runtime.InteropServices._Attribute
{

	// Constructors
	public InitializationEventAttribute(string eventName) {}

	// Methods
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}
	public virtual bool Match(object obj) {}
	public virtual bool IsDefaultAttribute() {}
	public Type GetType() {}
	public virtual string ToString() {}

	// Properties
	public string EventName { get{} }
	public object TypeId { get{} }
}

