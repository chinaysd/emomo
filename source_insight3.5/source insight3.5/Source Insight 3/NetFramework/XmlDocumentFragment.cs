public class XmlDocumentFragment : XmlNode, System.ICloneable, System.Collections.IEnumerable, System.Xml.XPath.IXPathNavigable
{

	// Methods
	public virtual XmlNode CloneNode(bool deep) {}
	public virtual void WriteTo(XmlWriter w) {}
	public virtual void WriteContentTo(XmlWriter w) {}
	public virtual XmlNode InsertBefore(XmlNode newChild, XmlNode refChild) {}
	public virtual XmlNode InsertAfter(XmlNode newChild, XmlNode refChild) {}
	public virtual XmlNode ReplaceChild(XmlNode newChild, XmlNode oldChild) {}
	public virtual XmlNode RemoveChild(XmlNode oldChild) {}
	public virtual XmlNode PrependChild(XmlNode newChild) {}
	public virtual XmlNode AppendChild(XmlNode newChild) {}
	public virtual void Normalize() {}
	public virtual bool Supports(string feature, string version) {}
	public virtual XmlNode Clone() {}
	public virtual void RemoveAll() {}
	public virtual string GetNamespaceOfPrefix(string prefix) {}
	public virtual string GetPrefixOfNamespace(string namespaceURI) {}
	public virtual System.Xml.XPath.XPathNavigator CreateNavigator() {}
	public XmlNode SelectSingleNode(string xpath) {}
	public XmlNode SelectSingleNode(string xpath, XmlNamespaceManager nsmgr) {}
	public XmlNodeList SelectNodes(string xpath) {}
	public XmlNodeList SelectNodes(string xpath, XmlNamespaceManager nsmgr) {}
	public System.Collections.IEnumerator GetEnumerator() {}
	public Type GetType() {}
	public virtual string ToString() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public string Name { get{} }
	public string LocalName { get{} }
	public XmlNodeType NodeType { get{} }
	public XmlNode ParentNode { get{} }
	public XmlDocument OwnerDocument { get{} }
	public string InnerXml { get{} set{} }
	public string Value { get{} set{} }
	public XmlNodeList ChildNodes { get{} }
	public XmlNode PreviousSibling { get{} }
	public XmlNode NextSibling { get{} }
	public XmlAttributeCollection Attributes { get{} }
	public XmlNode FirstChild { get{} }
	public XmlNode LastChild { get{} }
	public bool HasChildNodes { get{} }
	public string NamespaceURI { get{} }
	public string Prefix { get{} set{} }
	public bool IsReadOnly { get{} }
	public string InnerText { get{} set{} }
	public string OuterXml { get{} }
	public System.Xml.Schema.IXmlSchemaInfo SchemaInfo { get{} }
	public string BaseURI { get{} }
	public XmlElement Item { get{} }
	public XmlElement Item { get{} }
}

