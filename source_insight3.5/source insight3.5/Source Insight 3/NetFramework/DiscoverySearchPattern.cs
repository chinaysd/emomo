public class DiscoverySearchPattern
{

	// Methods
	public abstract virtual DiscoveryReference GetDiscoveryReference(string filename) {}
	public Type GetType() {}
	public virtual string ToString() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public string Pattern { get{} }
}

