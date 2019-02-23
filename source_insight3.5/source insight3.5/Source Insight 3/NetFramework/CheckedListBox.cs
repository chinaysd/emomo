public class CheckedListBox : ListBox, System.ComponentModel.IComponent, System.IDisposable, IOleControl, IOleObject, IOleInPlaceObject, IOleInPlaceActiveObject, IOleWindow, IViewObject, IViewObject2, IPersist, IPersistStreamInit, IPersistPropertyBag, IPersistStorage, IQuickActivate, ISupportOleDropSource, IDropTarget, System.ComponentModel.ISynchronizeInvoke, IWin32Window, System.Windows.Forms.Layout.IArrangedElement, IBindableComponent
{

	// Constructors
	public CheckedListBox() {}

	// Methods
	public CheckState GetItemCheckState(int index) {}
	public bool GetItemChecked(int index) {}
	public void SetItemCheckState(int index, CheckState value) {}
	public void SetItemChecked(int index, bool value) {}
	public void BeginUpdate() {}
	public void EndUpdate() {}
	public void ClearSelected() {}
	public int FindString(string s) {}
	public int FindString(string s, int startIndex) {}
	public int FindStringExact(string s) {}
	public int FindStringExact(string s, int startIndex) {}
	public int GetItemHeight(int index) {}
	public System.Drawing.Rectangle GetItemRectangle(int index) {}
	public bool GetSelected(int index) {}
	public int IndexFromPoint(System.Drawing.Point p) {}
	public int IndexFromPoint(int x, int y) {}
	public virtual void Refresh() {}
	public virtual void ResetBackColor() {}
	public virtual void ResetForeColor() {}
	public void SetSelected(int index, bool value) {}
	public virtual string ToString() {}
	public string GetItemText(object item) {}
	public void ResetImeMode() {}
	public void PerformLayout() {}
	public virtual bool PreProcessMessage(Message& msg) {}
	public virtual void ResetCursor() {}
	public virtual void ResetFont() {}
	public virtual void ResetRightToLeft() {}
	public virtual void ResetText() {}
	public void ResumeLayout() {}
	public void ResumeLayout(bool performLayout) {}
	public void SetBounds(int x, int y, int width, int height, BoundsSpecified specified) {}
	public void SuspendLayout() {}
	public void PerformLayout(Control affectedControl, string affectedProperty) {}
	public System.Drawing.Point PointToClient(System.Drawing.Point p) {}
	public System.Drawing.Point PointToScreen(System.Drawing.Point p) {}
	public PreProcessControlState PreProcessControlMessage(Message& msg) {}
	public System.Drawing.Rectangle RectangleToClient(System.Drawing.Rectangle r) {}
	public System.Drawing.Rectangle RectangleToScreen(System.Drawing.Rectangle r) {}
	public void Scale(float ratio) {}
	public void Scale(float dx, float dy) {}
	public void Scale(System.Drawing.SizeF factor) {}
	public void Select() {}
	public bool SelectNextControl(Control ctl, bool forward, bool tabStopOnly, bool nested, bool wrap) {}
	public void SendToBack() {}
	public void SetBounds(int x, int y, int width, int height) {}
	public void Show() {}
	public void Update() {}
	public virtual System.IAsyncResult BeginInvoke(System.Delegate method, object[] args) {}
	public void CreateControl() {}
	public virtual object EndInvoke(System.IAsyncResult asyncResult) {}
	public void Invalidate() {}
	public virtual object Invoke(System.Delegate method, object[] args) {}
	public System.IAsyncResult BeginInvoke(System.Delegate method) {}
	public void BringToFront() {}
	public bool Contains(Control ctl) {}
	public System.Drawing.Graphics CreateGraphics() {}
	public DragDropEffects DoDragDrop(object data, DragDropEffects allowedEffects) {}
	public void DrawToBitmap(System.Drawing.Bitmap bitmap, System.Drawing.Rectangle targetBounds) {}
	public Form FindForm() {}
	public bool Focus() {}
	public Control GetChildAtPoint(System.Drawing.Point pt, GetChildAtPointSkip skipValue) {}
	public Control GetChildAtPoint(System.Drawing.Point pt) {}
	public IContainerControl GetContainerControl() {}
	public Control GetNextControl(Control ctl, bool forward) {}
	public void Hide() {}
	public void Invalidate(System.Drawing.Region region) {}
	public void Invalidate(System.Drawing.Region region, bool invalidateChildren) {}
	public void Invalidate(bool invalidateChildren) {}
	public void Invalidate(System.Drawing.Rectangle rc) {}
	public void Invalidate(System.Drawing.Rectangle rc, bool invalidateChildren) {}
	public object Invoke(System.Delegate method) {}
	public virtual System.Drawing.Size GetPreferredSize(System.Drawing.Size proposedSize) {}
	public void ResetBindings() {}
	public virtual void Dispose() {}
	public virtual object GetLifetimeService() {}
	public virtual object InitializeLifetimeService() {}
	public virtual System.Runtime.Remoting.ObjRef CreateObjRef(Type requestedType) {}
	public Type GetType() {}
	public virtual bool Equals(object obj) {}
	public virtual int GetHashCode() {}

	// Properties
	public bool CheckOnClick { get{} set{} }
	public CheckedIndexCollection CheckedIndices { get{} }
	public CheckedItemCollection CheckedItems { get{} }
	public object DataSource { get{} set{} }
	public string DisplayMember { get{} set{} }
	public DrawMode DrawMode { get{} set{} }
	public int ItemHeight { get{} set{} }
	public ObjectCollection Items { get{} }
	public SelectionMode SelectionMode { get{} set{} }
	public bool ThreeDCheckBoxes { get{} set{} }
	public bool UseCompatibleTextRendering { get{} set{} }
	public string ValueMember { get{} set{} }
	public Padding Padding { get{} set{} }
	public System.Drawing.Color BackColor { get{} set{} }
	public System.Drawing.Image BackgroundImage { get{} set{} }
	public ImageLayout BackgroundImageLayout { get{} set{} }
	public BorderStyle BorderStyle { get{} set{} }
	public int ColumnWidth { get{} set{} }
	public bool UseCustomTabOffsets { get{} set{} }
	public System.Drawing.Font Font { get{} set{} }
	public System.Drawing.Color ForeColor { get{} set{} }
	public int HorizontalExtent { get{} set{} }
	public bool HorizontalScrollbar { get{} set{} }
	public bool IntegralHeight { get{} set{} }
	public ObjectCollection Items { get{} }
	public bool MultiColumn { get{} set{} }
	public int PreferredHeight { get{} }
	public RightToLeft RightToLeft { get{} set{} }
	public bool ScrollAlwaysVisible { get{} set{} }
	public int SelectedIndex { get{} set{} }
	public SelectedIndexCollection SelectedIndices { get{} }
	public object SelectedItem { get{} set{} }
	public SelectedObjectCollection SelectedItems { get{} }
	public bool Sorted { get{} set{} }
	public string Text { get{} set{} }
	public int TopIndex { get{} set{} }
	public bool UseTabStops { get{} set{} }
	public IntegerCollection CustomTabOffsets { get{} }
	public System.IFormatProvider FormatInfo { get{} set{} }
	public string FormatString { get{} set{} }
	public bool FormattingEnabled { get{} set{} }
	public object SelectedValue { get{} set{} }
	public AccessibleObject AccessibilityObject { get{} }
	public string AccessibleDefaultActionDescription { get{} set{} }
	public string AccessibleDescription { get{} set{} }
	public string AccessibleName { get{} set{} }
	public AccessibleRole AccessibleRole { get{} set{} }
	public bool AllowDrop { get{} set{} }
	public AnchorStyles Anchor { get{} set{} }
	public bool AutoSize { get{} set{} }
	public System.Drawing.Point AutoScrollOffset { get{} set{} }
	public System.Windows.Forms.Layout.LayoutEngine LayoutEngine { get{} }
	public BindingContext BindingContext { get{} set{} }
	public int Bottom { get{} }
	public System.Drawing.Rectangle Bounds { get{} set{} }
	public bool CanFocus { get{} }
	public bool CanSelect { get{} }
	public bool Capture { get{} set{} }
	public bool CausesValidation { get{} set{} }
	public System.Drawing.Rectangle ClientRectangle { get{} }
	public System.Drawing.Size ClientSize { get{} set{} }
	public string CompanyName { get{} }
	public bool ContainsFocus { get{} }
	public ContextMenu ContextMenu { get{} set{} }
	public ContextMenuStrip ContextMenuStrip { get{} set{} }
	public ControlCollection Controls { get{} }
	public bool Created { get{} }
	public Cursor Cursor { get{} set{} }
	public ControlBindingsCollection DataBindings { get{} }
	public System.Drawing.Rectangle DisplayRectangle { get{} }
	public bool IsDisposed { get{} }
	public bool Disposing { get{} }
	public DockStyle Dock { get{} set{} }
	public bool Enabled { get{} set{} }
	public bool Focused { get{} }
	public System.IntPtr Handle { get{} }
	public bool HasChildren { get{} }
	public int Height { get{} set{} }
	public bool IsHandleCreated { get{} }
	public bool InvokeRequired { get{} }
	public bool IsAccessible { get{} set{} }
	public bool IsMirrored { get{} }
	public int Left { get{} set{} }
	public System.Drawing.Point Location { get{} set{} }
	public Padding Margin { get{} set{} }
	public System.Drawing.Size MaximumSize { get{} set{} }
	public System.Drawing.Size MinimumSize { get{} set{} }
	public string Name { get{} set{} }
	public Control Parent { get{} set{} }
	public string ProductName { get{} }
	public string ProductVersion { get{} }
	public bool RecreatingHandle { get{} }
	public System.Drawing.Region Region { get{} set{} }
	public int Right { get{} }
	public System.ComponentModel.ISite Site { get{} set{} }
	public System.Drawing.Size Size { get{} set{} }
	public int TabIndex { get{} set{} }
	public bool TabStop { get{} set{} }
	public object Tag { get{} set{} }
	public int Top { get{} set{} }
	public Control TopLevelControl { get{} }
	public bool UseWaitCursor { get{} set{} }
	public bool Visible { get{} set{} }
	public int Width { get{} set{} }
	public IWindowTarget WindowTarget { get{} set{} }
	public System.Drawing.Size PreferredSize { get{} }
	public ImeMode ImeMode { get{} set{} }
	public System.ComponentModel.IContainer Container { get{} }

	// Events
	public event System.EventHandler DataSourceChanged;
	public event System.EventHandler DisplayMemberChanged;
	public event System.Windows.Forms.ItemCheckEventHandler ItemCheck;
	public event System.EventHandler Click;
	public event System.Windows.Forms.MouseEventHandler MouseClick;
	public event System.Windows.Forms.DrawItemEventHandler DrawItem;
	public event System.Windows.Forms.MeasureItemEventHandler MeasureItem;
	public event System.EventHandler ValueMemberChanged;
	public event System.EventHandler BackgroundImageChanged;
	public event System.EventHandler BackgroundImageLayoutChanged;
	public event System.EventHandler TextChanged;
	public event System.EventHandler PaddingChanged;
	public event System.Windows.Forms.PaintEventHandler Paint;
	public event System.EventHandler SelectedIndexChanged;
	public event System.Windows.Forms.ListControlConvertEventHandler Format;
	public event System.EventHandler FormatInfoChanged;
	public event System.EventHandler FormatStringChanged;
	public event System.EventHandler FormattingEnabledChanged;
	public event System.EventHandler SelectedValueChanged;
	public event System.EventHandler AutoSizeChanged;
	public event System.EventHandler BackColorChanged;
	public event System.EventHandler BindingContextChanged;
	public event System.EventHandler CausesValidationChanged;
	public event System.EventHandler ClientSizeChanged;
	public event System.EventHandler ContextMenuChanged;
	public event System.EventHandler ContextMenuStripChanged;
	public event System.EventHandler CursorChanged;
	public event System.EventHandler DockChanged;
	public event System.EventHandler EnabledChanged;
	public event System.EventHandler FontChanged;
	public event System.EventHandler ForeColorChanged;
	public event System.EventHandler LocationChanged;
	public event System.EventHandler MarginChanged;
	public event System.EventHandler RegionChanged;
	public event System.EventHandler RightToLeftChanged;
	public event System.EventHandler SizeChanged;
	public event System.EventHandler TabIndexChanged;
	public event System.EventHandler TabStopChanged;
	public event System.EventHandler VisibleChanged;
	public event System.Windows.Forms.ControlEventHandler ControlAdded;
	public event System.Windows.Forms.ControlEventHandler ControlRemoved;
	public event System.Windows.Forms.DragEventHandler DragDrop;
	public event System.Windows.Forms.DragEventHandler DragEnter;
	public event System.Windows.Forms.DragEventHandler DragOver;
	public event System.EventHandler DragLeave;
	public event System.Windows.Forms.GiveFeedbackEventHandler GiveFeedback;
	public event System.EventHandler HandleCreated;
	public event System.EventHandler HandleDestroyed;
	public event System.Windows.Forms.HelpEventHandler HelpRequested;
	public event System.Windows.Forms.InvalidateEventHandler Invalidated;
	public event System.Windows.Forms.QueryContinueDragEventHandler QueryContinueDrag;
	public event System.Windows.Forms.QueryAccessibilityHelpEventHandler QueryAccessibilityHelp;
	public event System.EventHandler DoubleClick;
	public event System.EventHandler Enter;
	public event System.EventHandler GotFocus;
	public event System.Windows.Forms.KeyEventHandler KeyDown;
	public event System.Windows.Forms.KeyPressEventHandler KeyPress;
	public event System.Windows.Forms.KeyEventHandler KeyUp;
	public event System.Windows.Forms.LayoutEventHandler Layout;
	public event System.EventHandler Leave;
	public event System.EventHandler LostFocus;
	public event System.Windows.Forms.MouseEventHandler MouseDoubleClick;
	public event System.EventHandler MouseCaptureChanged;
	public event System.Windows.Forms.MouseEventHandler MouseDown;
	public event System.EventHandler MouseEnter;
	public event System.EventHandler MouseLeave;
	public event System.EventHandler MouseHover;
	public event System.Windows.Forms.MouseEventHandler MouseMove;
	public event System.Windows.Forms.MouseEventHandler MouseUp;
	public event System.Windows.Forms.MouseEventHandler MouseWheel;
	public event System.EventHandler Move;
	public event System.Windows.Forms.PreviewKeyDownEventHandler PreviewKeyDown;
	public event System.EventHandler Resize;
	public event System.Windows.Forms.UICuesEventHandler ChangeUICues;
	public event System.EventHandler StyleChanged;
	public event System.EventHandler SystemColorsChanged;
	public event System.ComponentModel.CancelEventHandler Validating;
	public event System.EventHandler Validated;
	public event System.EventHandler ParentChanged;
	public event System.EventHandler ImeModeChanged;
	public event System.EventHandler Disposed;
}

