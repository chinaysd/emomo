public class ListChildrenAccessRule : ActiveDirectoryAccessRule
{

	// Constructors
	public ListChildrenAccessRule(System.Security.Principal.IdentityReference identity, System.Security.AccessControl.AccessControlType type) {}
	public ListChildrenAccessRule(System.Security.Principal.IdentityReference identity, System.Security.AccessControl.AccessControlType type, ActiveDirectorySecurityInheritance inheritanceType) {}
	public ListChildrenAccessRule(System.Security.Principal.IdentityReference identity, System.Security.AccessControl.AccessControlType type, ActiveDirectorySecurityInheritance inheritanceType, System.Guid inheritedObjectType) {}

	// Methods
	public Type GetType() {}
	public virtual string ToString() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public ActiveDirectoryRights ActiveDirectoryRights { get{} }
	public ActiveDirectorySecurityInheritance InheritanceType { get{} }
	public System.Guid ObjectType { get{} }
	public System.Guid InheritedObjectType { get{} }
	public System.Security.AccessControl.ObjectAceFlags ObjectFlags { get{} }
	public System.Security.AccessControl.AccessControlType AccessControlType { get{} }
	public System.Security.Principal.IdentityReference IdentityReference { get{} }
	public bool IsInherited { get{} }
	public System.Security.AccessControl.InheritanceFlags InheritanceFlags { get{} }
	public System.Security.AccessControl.PropagationFlags PropagationFlags { get{} }
}

