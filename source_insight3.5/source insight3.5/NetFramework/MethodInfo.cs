public class MethodInfo : MethodBase, ICustomAttributeProvider, System.Runtime.InteropServices._MemberInfo, System.Runtime.InteropServices._MethodBase, System.Runtime.InteropServices._MethodInfo
{

	// Methods
	public abstract virtual MethodInfo GetBaseDefinition() {}
	public virtual Type[] GetGenericArguments() {}
	public virtual MethodInfo GetGenericMethodDefinition() {}
	public virtual MethodInfo MakeGenericMethod(Type[] typeArguments) {}
	public abstract virtual ParameterInfo[] GetParameters() {}
	public abstract virtual MethodImplAttributes GetMethodImplementationFlags() {}
	public abstract virtual object Invoke(object obj, BindingFlags invokeAttr, Binder binder, object[] parameters, System.Globalization.CultureInfo culture) {}
	public virtual object Invoke(object obj, object[] parameters) {}
	public virtual MethodBody GetMethodBody() {}
	public abstract virtual object[] GetCustomAttributes(bool inherit) {}
	public abstract virtual object[] GetCustomAttributes(Type attributeType, bool inherit) {}
	public abstract virtual bool IsDefined(Type attributeType, bool inherit) {}
	public Type GetType() {}
	public virtual string ToString() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public MemberTypes MemberType { get{} }
	public Type ReturnType { get{} }
	public ParameterInfo ReturnParameter { get{} }
	public ICustomAttributeProvider ReturnTypeCustomAttributes { get{} }
	public bool IsGenericMethodDefinition { get{} }
	public bool ContainsGenericParameters { get{} }
	public bool IsGenericMethod { get{} }
	public System.RuntimeMethodHandle MethodHandle { get{} }
	public MethodAttributes Attributes { get{} }
	public CallingConventions CallingConvention { get{} }
	public bool IsPublic { get{} }
	public bool IsPrivate { get{} }
	public bool IsFamily { get{} }
	public bool IsAssembly { get{} }
	public bool IsFamilyAndAssembly { get{} }
	public bool IsFamilyOrAssembly { get{} }
	public bool IsStatic { get{} }
	public bool IsFinal { get{} }
	public bool IsVirtual { get{} }
	public bool IsHideBySig { get{} }
	public bool IsAbstract { get{} }
	public bool IsSpecialName { get{} }
	public bool IsConstructor { get{} }
	public string Name { get{} }
	public Type DeclaringType { get{} }
	public Type ReflectedType { get{} }
	public int MetadataToken { get{} }
	public Module Module { get{} }
}

