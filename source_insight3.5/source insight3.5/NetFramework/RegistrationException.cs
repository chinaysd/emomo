public class RegistrationException : System.SystemException, System.Runtime.Serialization.ISerializable, System.Runtime.InteropServices._Exception
{

	// Constructors
	public RegistrationException() {}
	public RegistrationException(string msg) {}
	public RegistrationException(string msg, System.Exception inner) {}

	// Methods
	public virtual void GetObjectData(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext ctx) {}
	public virtual System.Exception GetBaseException() {}
	public virtual string ToString() {}
	public virtual Type GetType() {}
	public Type GetType() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public RegistrationErrorInfo[] ErrorInfo { get{} }
	public string Message { get{} }
	public System.Collections.IDictionary Data { get{} }
	public System.Exception InnerException { get{} }
	public System.Reflection.MethodBase TargetSite { get{} }
	public string StackTrace { get{} }
	public string HelpLink { get{} set{} }
	public string Source { get{} set{} }
}

