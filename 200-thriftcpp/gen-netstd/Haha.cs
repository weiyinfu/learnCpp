/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using Thrift;
using Thrift.Collections;

using Thrift.Protocol;
using Thrift.Protocol.Entities;
using Thrift.Protocol.Utilities;
using Thrift.Transport;
using Thrift.Transport.Client;
using Thrift.Transport.Server;
using Thrift.Processor;


public partial class Haha
{
  public interface IAsync
  {
    Task<string> hahaAsync(string s, CancellationToken cancellationToken = default(CancellationToken));

    Task<int> bagaAsync(int one, int two, CancellationToken cancellationToken = default(CancellationToken));

  }


  public class Client : TBaseClient, IDisposable, IAsync
  {
    public Client(TProtocol protocol) : this(protocol, protocol)
    {
    }

    public Client(TProtocol inputProtocol, TProtocol outputProtocol) : base(inputProtocol, outputProtocol)    {
    }
    public async Task<string> hahaAsync(string s, CancellationToken cancellationToken = default(CancellationToken))
    {
      await OutputProtocol.WriteMessageBeginAsync(new TMessage("haha", TMessageType.Call, SeqId), cancellationToken);
      
      var args = new hahaArgs();
      args.S = s;
      
      await args.WriteAsync(OutputProtocol, cancellationToken);
      await OutputProtocol.WriteMessageEndAsync(cancellationToken);
      await OutputProtocol.Transport.FlushAsync(cancellationToken);
      
      var msg = await InputProtocol.ReadMessageBeginAsync(cancellationToken);
      if (msg.Type == TMessageType.Exception)
      {
        var x = await TApplicationException.ReadAsync(InputProtocol, cancellationToken);
        await InputProtocol.ReadMessageEndAsync(cancellationToken);
        throw x;
      }

      var result = new hahaResult();
      await result.ReadAsync(InputProtocol, cancellationToken);
      await InputProtocol.ReadMessageEndAsync(cancellationToken);
      if (result.__isset.success)
      {
        return result.Success;
      }
      throw new TApplicationException(TApplicationException.ExceptionType.MissingResult, "haha failed: unknown result");
    }

    public async Task<int> bagaAsync(int one, int two, CancellationToken cancellationToken = default(CancellationToken))
    {
      await OutputProtocol.WriteMessageBeginAsync(new TMessage("baga", TMessageType.Call, SeqId), cancellationToken);
      
      var args = new bagaArgs();
      args.One = one;
      args.Two = two;
      
      await args.WriteAsync(OutputProtocol, cancellationToken);
      await OutputProtocol.WriteMessageEndAsync(cancellationToken);
      await OutputProtocol.Transport.FlushAsync(cancellationToken);
      
      var msg = await InputProtocol.ReadMessageBeginAsync(cancellationToken);
      if (msg.Type == TMessageType.Exception)
      {
        var x = await TApplicationException.ReadAsync(InputProtocol, cancellationToken);
        await InputProtocol.ReadMessageEndAsync(cancellationToken);
        throw x;
      }

      var result = new bagaResult();
      await result.ReadAsync(InputProtocol, cancellationToken);
      await InputProtocol.ReadMessageEndAsync(cancellationToken);
      if (result.__isset.success)
      {
        return result.Success;
      }
      throw new TApplicationException(TApplicationException.ExceptionType.MissingResult, "baga failed: unknown result");
    }

  }

  public class AsyncProcessor : ITAsyncProcessor
  {
    private IAsync _iAsync;

    public AsyncProcessor(IAsync iAsync)
    {
      if (iAsync == null) throw new ArgumentNullException(nameof(iAsync));

      _iAsync = iAsync;
      processMap_["haha"] = haha_ProcessAsync;
      processMap_["baga"] = baga_ProcessAsync;
    }

    protected delegate Task ProcessFunction(int seqid, TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken);
    protected Dictionary<string, ProcessFunction> processMap_ = new Dictionary<string, ProcessFunction>();

    public async Task<bool> ProcessAsync(TProtocol iprot, TProtocol oprot)
    {
      return await ProcessAsync(iprot, oprot, CancellationToken.None);
    }

    public async Task<bool> ProcessAsync(TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken)
    {
      try
      {
        var msg = await iprot.ReadMessageBeginAsync(cancellationToken);

        ProcessFunction fn;
        processMap_.TryGetValue(msg.Name, out fn);

        if (fn == null)
        {
          await TProtocolUtil.SkipAsync(iprot, TType.Struct, cancellationToken);
          await iprot.ReadMessageEndAsync(cancellationToken);
          var x = new TApplicationException (TApplicationException.ExceptionType.UnknownMethod, "Invalid method name: '" + msg.Name + "'");
          await oprot.WriteMessageBeginAsync(new TMessage(msg.Name, TMessageType.Exception, msg.SeqID), cancellationToken);
          await x.WriteAsync(oprot, cancellationToken);
          await oprot.WriteMessageEndAsync(cancellationToken);
          await oprot.Transport.FlushAsync(cancellationToken);
          return true;
        }

        await fn(msg.SeqID, iprot, oprot, cancellationToken);

      }
      catch (IOException)
      {
        return false;
      }

      return true;
    }

    public async Task haha_ProcessAsync(int seqid, TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken)
    {
      var args = new hahaArgs();
      await args.ReadAsync(iprot, cancellationToken);
      await iprot.ReadMessageEndAsync(cancellationToken);
      var result = new hahaResult();
      try
      {
        result.Success = await _iAsync.hahaAsync(args.S, cancellationToken);
        await oprot.WriteMessageBeginAsync(new TMessage("haha", TMessageType.Reply, seqid), cancellationToken); 
        await result.WriteAsync(oprot, cancellationToken);
      }
      catch (TTransportException)
      {
        throw;
      }
      catch (Exception ex)
      {
        Console.Error.WriteLine("Error occurred in processor:");
        Console.Error.WriteLine(ex.ToString());
        var x = new TApplicationException(TApplicationException.ExceptionType.InternalError," Internal error.");
        await oprot.WriteMessageBeginAsync(new TMessage("haha", TMessageType.Exception, seqid), cancellationToken);
        await x.WriteAsync(oprot, cancellationToken);
      }
      await oprot.WriteMessageEndAsync(cancellationToken);
      await oprot.Transport.FlushAsync(cancellationToken);
    }

    public async Task baga_ProcessAsync(int seqid, TProtocol iprot, TProtocol oprot, CancellationToken cancellationToken)
    {
      var args = new bagaArgs();
      await args.ReadAsync(iprot, cancellationToken);
      await iprot.ReadMessageEndAsync(cancellationToken);
      var result = new bagaResult();
      try
      {
        result.Success = await _iAsync.bagaAsync(args.One, args.Two, cancellationToken);
        await oprot.WriteMessageBeginAsync(new TMessage("baga", TMessageType.Reply, seqid), cancellationToken); 
        await result.WriteAsync(oprot, cancellationToken);
      }
      catch (TTransportException)
      {
        throw;
      }
      catch (Exception ex)
      {
        Console.Error.WriteLine("Error occurred in processor:");
        Console.Error.WriteLine(ex.ToString());
        var x = new TApplicationException(TApplicationException.ExceptionType.InternalError," Internal error.");
        await oprot.WriteMessageBeginAsync(new TMessage("baga", TMessageType.Exception, seqid), cancellationToken);
        await x.WriteAsync(oprot, cancellationToken);
      }
      await oprot.WriteMessageEndAsync(cancellationToken);
      await oprot.Transport.FlushAsync(cancellationToken);
    }

  }


  public partial class hahaArgs : TBase
  {
    private string _s;

    public string S
    {
      get
      {
        return _s;
      }
      set
      {
        __isset.s = true;
        this._s = value;
      }
    }


    public Isset __isset;
    public struct Isset
    {
      public bool s;
    }

    public hahaArgs()
    {
    }

    public async Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        TField field;
        await iprot.ReadStructBeginAsync(cancellationToken);
        while (true)
        {
          field = await iprot.ReadFieldBeginAsync(cancellationToken);
          if (field.Type == TType.Stop)
          {
            break;
          }

          switch (field.ID)
          {
            case -1:
              if (field.Type == TType.String)
              {
                S = await iprot.ReadStringAsync(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            default: 
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              break;
          }

          await iprot.ReadFieldEndAsync(cancellationToken);
        }

        await iprot.ReadStructEndAsync(cancellationToken);
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public async Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
    {
      oprot.IncrementRecursionDepth();
      try
      {
        var struc = new TStruct("haha_args");
        await oprot.WriteStructBeginAsync(struc, cancellationToken);
        var field = new TField();
        if (S != null && __isset.s)
        {
          field.Name = "s";
          field.Type = TType.String;
          field.ID = -1;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteStringAsync(S, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        await oprot.WriteFieldStopAsync(cancellationToken);
        await oprot.WriteStructEndAsync(cancellationToken);
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override bool Equals(object that)
    {
      var other = that as hahaArgs;
      if (other == null) return false;
      if (ReferenceEquals(this, other)) return true;
      return ((__isset.s == other.__isset.s) && ((!__isset.s) || (System.Object.Equals(S, other.S))));
    }

    public override int GetHashCode() {
      int hashcode = 157;
      unchecked {
        if(__isset.s)
          hashcode = (hashcode * 397) + S.GetHashCode();
      }
      return hashcode;
    }

    public override string ToString()
    {
      var sb = new StringBuilder("haha_args(");
      bool __first = true;
      if (S != null && __isset.s)
      {
        if(!__first) { sb.Append(", "); }
        __first = false;
        sb.Append("S: ");
        sb.Append(S);
      }
      sb.Append(")");
      return sb.ToString();
    }
  }


  public partial class hahaResult : TBase
  {
    private string _success;

    public string Success
    {
      get
      {
        return _success;
      }
      set
      {
        __isset.success = true;
        this._success = value;
      }
    }


    public Isset __isset;
    public struct Isset
    {
      public bool success;
    }

    public hahaResult()
    {
    }

    public async Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        TField field;
        await iprot.ReadStructBeginAsync(cancellationToken);
        while (true)
        {
          field = await iprot.ReadFieldBeginAsync(cancellationToken);
          if (field.Type == TType.Stop)
          {
            break;
          }

          switch (field.ID)
          {
            case 0:
              if (field.Type == TType.String)
              {
                Success = await iprot.ReadStringAsync(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            default: 
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              break;
          }

          await iprot.ReadFieldEndAsync(cancellationToken);
        }

        await iprot.ReadStructEndAsync(cancellationToken);
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public async Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
    {
      oprot.IncrementRecursionDepth();
      try
      {
        var struc = new TStruct("haha_result");
        await oprot.WriteStructBeginAsync(struc, cancellationToken);
        var field = new TField();

        if(this.__isset.success)
        {
          if (Success != null)
          {
            field.Name = "Success";
            field.Type = TType.String;
            field.ID = 0;
            await oprot.WriteFieldBeginAsync(field, cancellationToken);
            await oprot.WriteStringAsync(Success, cancellationToken);
            await oprot.WriteFieldEndAsync(cancellationToken);
          }
        }
        await oprot.WriteFieldStopAsync(cancellationToken);
        await oprot.WriteStructEndAsync(cancellationToken);
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override bool Equals(object that)
    {
      var other = that as hahaResult;
      if (other == null) return false;
      if (ReferenceEquals(this, other)) return true;
      return ((__isset.success == other.__isset.success) && ((!__isset.success) || (System.Object.Equals(Success, other.Success))));
    }

    public override int GetHashCode() {
      int hashcode = 157;
      unchecked {
        if(__isset.success)
          hashcode = (hashcode * 397) + Success.GetHashCode();
      }
      return hashcode;
    }

    public override string ToString()
    {
      var sb = new StringBuilder("haha_result(");
      bool __first = true;
      if (Success != null && __isset.success)
      {
        if(!__first) { sb.Append(", "); }
        __first = false;
        sb.Append("Success: ");
        sb.Append(Success);
      }
      sb.Append(")");
      return sb.ToString();
    }
  }


  public partial class bagaArgs : TBase
  {
    private int _one;
    private int _two;

    public int One
    {
      get
      {
        return _one;
      }
      set
      {
        __isset.one = true;
        this._one = value;
      }
    }

    public int Two
    {
      get
      {
        return _two;
      }
      set
      {
        __isset.two = true;
        this._two = value;
      }
    }


    public Isset __isset;
    public struct Isset
    {
      public bool one;
      public bool two;
    }

    public bagaArgs()
    {
    }

    public async Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        TField field;
        await iprot.ReadStructBeginAsync(cancellationToken);
        while (true)
        {
          field = await iprot.ReadFieldBeginAsync(cancellationToken);
          if (field.Type == TType.Stop)
          {
            break;
          }

          switch (field.ID)
          {
            case -1:
              if (field.Type == TType.I32)
              {
                One = await iprot.ReadI32Async(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            case -2:
              if (field.Type == TType.I32)
              {
                Two = await iprot.ReadI32Async(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            default: 
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              break;
          }

          await iprot.ReadFieldEndAsync(cancellationToken);
        }

        await iprot.ReadStructEndAsync(cancellationToken);
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public async Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
    {
      oprot.IncrementRecursionDepth();
      try
      {
        var struc = new TStruct("baga_args");
        await oprot.WriteStructBeginAsync(struc, cancellationToken);
        var field = new TField();
        if (__isset.two)
        {
          field.Name = "two";
          field.Type = TType.I32;
          field.ID = -2;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteI32Async(Two, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        if (__isset.one)
        {
          field.Name = "one";
          field.Type = TType.I32;
          field.ID = -1;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteI32Async(One, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        await oprot.WriteFieldStopAsync(cancellationToken);
        await oprot.WriteStructEndAsync(cancellationToken);
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override bool Equals(object that)
    {
      var other = that as bagaArgs;
      if (other == null) return false;
      if (ReferenceEquals(this, other)) return true;
      return ((__isset.one == other.__isset.one) && ((!__isset.one) || (System.Object.Equals(One, other.One))))
        && ((__isset.two == other.__isset.two) && ((!__isset.two) || (System.Object.Equals(Two, other.Two))));
    }

    public override int GetHashCode() {
      int hashcode = 157;
      unchecked {
        if(__isset.one)
          hashcode = (hashcode * 397) + One.GetHashCode();
        if(__isset.two)
          hashcode = (hashcode * 397) + Two.GetHashCode();
      }
      return hashcode;
    }

    public override string ToString()
    {
      var sb = new StringBuilder("baga_args(");
      bool __first = true;
      if (__isset.one)
      {
        if(!__first) { sb.Append(", "); }
        __first = false;
        sb.Append("One: ");
        sb.Append(One);
      }
      if (__isset.two)
      {
        if(!__first) { sb.Append(", "); }
        __first = false;
        sb.Append("Two: ");
        sb.Append(Two);
      }
      sb.Append(")");
      return sb.ToString();
    }
  }


  public partial class bagaResult : TBase
  {
    private int _success;

    public int Success
    {
      get
      {
        return _success;
      }
      set
      {
        __isset.success = true;
        this._success = value;
      }
    }


    public Isset __isset;
    public struct Isset
    {
      public bool success;
    }

    public bagaResult()
    {
    }

    public async Task ReadAsync(TProtocol iprot, CancellationToken cancellationToken)
    {
      iprot.IncrementRecursionDepth();
      try
      {
        TField field;
        await iprot.ReadStructBeginAsync(cancellationToken);
        while (true)
        {
          field = await iprot.ReadFieldBeginAsync(cancellationToken);
          if (field.Type == TType.Stop)
          {
            break;
          }

          switch (field.ID)
          {
            case 0:
              if (field.Type == TType.I32)
              {
                Success = await iprot.ReadI32Async(cancellationToken);
              }
              else
              {
                await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              }
              break;
            default: 
              await TProtocolUtil.SkipAsync(iprot, field.Type, cancellationToken);
              break;
          }

          await iprot.ReadFieldEndAsync(cancellationToken);
        }

        await iprot.ReadStructEndAsync(cancellationToken);
      }
      finally
      {
        iprot.DecrementRecursionDepth();
      }
    }

    public async Task WriteAsync(TProtocol oprot, CancellationToken cancellationToken)
    {
      oprot.IncrementRecursionDepth();
      try
      {
        var struc = new TStruct("baga_result");
        await oprot.WriteStructBeginAsync(struc, cancellationToken);
        var field = new TField();

        if(this.__isset.success)
        {
          field.Name = "Success";
          field.Type = TType.I32;
          field.ID = 0;
          await oprot.WriteFieldBeginAsync(field, cancellationToken);
          await oprot.WriteI32Async(Success, cancellationToken);
          await oprot.WriteFieldEndAsync(cancellationToken);
        }
        await oprot.WriteFieldStopAsync(cancellationToken);
        await oprot.WriteStructEndAsync(cancellationToken);
      }
      finally
      {
        oprot.DecrementRecursionDepth();
      }
    }

    public override bool Equals(object that)
    {
      var other = that as bagaResult;
      if (other == null) return false;
      if (ReferenceEquals(this, other)) return true;
      return ((__isset.success == other.__isset.success) && ((!__isset.success) || (System.Object.Equals(Success, other.Success))));
    }

    public override int GetHashCode() {
      int hashcode = 157;
      unchecked {
        if(__isset.success)
          hashcode = (hashcode * 397) + Success.GetHashCode();
      }
      return hashcode;
    }

    public override string ToString()
    {
      var sb = new StringBuilder("baga_result(");
      bool __first = true;
      if (__isset.success)
      {
        if(!__first) { sb.Append(", "); }
        __first = false;
        sb.Append("Success: ");
        sb.Append(Success);
      }
      sb.Append(")");
      return sb.ToString();
    }
  }

}