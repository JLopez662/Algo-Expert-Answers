Imports System.Collections.Generic
Imports System.Linq
Imports System.Text
Imports System.Threading.Tasks

Module Module1

    Function isSorted(ByVal array As List(Of Integer)) As Boolean 
        For i As Integer = 0 To array.Count() - 2
            If array(i) > array(i+1) Then 
                Return False
            End If
        Next 
        
        Return True 
    End Function

    Function bubbleSort(ByVal array As List(Of Integer)) As List(Of Integer)

        If isSorted(array) Then 
            Return array
        End If

        Dim size = array.Count()

        While size > 1

            For i As Integer = 0 To size - 2
                If array(i) > array(i+1) Then
                    Dim temp = array(i)
                    array(i) = array(i+1)
                    array(i+1) = temp
                End If
            Next 
            size -= 1
        End While 

        Return array

    End Function

    Sub Main()
        Dim arr As List(Of Integer) = New List(Of Integer)({5, 3, 8, 6, 7, 2})

        Console.WriteLine("Unsorted array: ")

        For Each num As Integer In arr
            Console.Write(num & " ")
        Next

        Console.WriteLine()

        arr = bubbleSort(arr)

        Console.WriteLine("Sorted array: ")
        For Each num As Integer in arr
            Console.Write(num & " ")
        Next

        Console.Writeline()
        Console.ReadLine()
    End Sub
End Module