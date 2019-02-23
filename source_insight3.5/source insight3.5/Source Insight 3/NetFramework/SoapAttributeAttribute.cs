public class SoapAttributeAttribute : System.Attribute, System.Runtime.InteropServices._Attribute
{

	// Constructors
	public SoapAttributeAttribute() {}
	public SoapAttributeAttribute(string attributeName) {}

	// Methods
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}
	public virtual bool Match(object obj) {}
	public virtual bool IsDefaultAttribute() {}
	public Type GetType() {}
	public virtual string ToString() {}

	// Properties
	public string AttributeName { get{} set{} }
	public string Namespace { get{} set{} }
	public string DataType { get{} set{} }
	public object TypeId { get{} }
}

