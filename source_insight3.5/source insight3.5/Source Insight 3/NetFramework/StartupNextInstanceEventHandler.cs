public class StartupNextInstanceEventHandler : System.MulticastDelegate, System.ICloneable, System.Runtime.Serialization.ISerializable
{

	// Constructors
	public StartupNextInstanceEventHandler(object TargetObject, System.IntPtr TargetMethod) {}

	// Methods
	public virtual System.IAsyncResult BeginInvoke(object sender, StartupNextInstanceEventArgs e, System.AsyncCallback DelegateCallback, object DelegateAsyncState) {}
	public virtual void EndInvoke(System.IAsyncResult DelegateAsyncResult) {}
	public virtual void Invoke(object sender, StartupNextInstanceEventArgs e) {}
	public virtual void GetObjectData(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) {}
	public virtual bool Equals(object obj) {}
	public virtual System.Delegate[] GetInvocationList() {}
	public virtual int GetHashCode() {}
	public object DynamicInvoke(object[] args) {}
	public virtual object Clone() {}
	public Type GetType() {}
	public virtual string ToString() {}

	// Properties
	public System.Reflection.MethodInfo Method { get{} }
	public object Target { get{} }
}

