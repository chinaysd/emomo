public class MulticastDelegate : Delegate, ICloneable, System.Runtime.Serialization.ISerializable
{

	// Methods
	public virtual void GetObjectData(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) {}
	public virtual bool Equals(object obj) {}
	public virtual Delegate[] GetInvocationList() {}
	public static bool op_Equality(MulticastDelegate d1, MulticastDelegate d2) {}
	public static bool op_Inequality(MulticastDelegate d1, MulticastDelegate d2) {}
	public virtual int GetHashCode() {}
	public object DynamicInvoke(object[] args) {}
	public virtual object Clone() {}
	public Type GetType() {}
	public virtual string ToString() {}

	// Properties
	public System.Reflection.MethodInfo Method { get{} }
	public object Target { get{} }
}

