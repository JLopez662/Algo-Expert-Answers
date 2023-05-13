Imports System.Collections.Generic
Imports System 

Module Module1
    Sub Main()
        Dim arr As List(Of Integer) = New List(Of Integer)({3, 1, 4, 2})
        Console.WriteLine("Unsorted array: ")
        Console.WriteLine(String.Join(",", arr))
        arr = InsertionSort(arr)
        Console.WriteLine("Sorted array: ")
        Console.WriteLine(String.Join(",", arr))
    End Sub

    Function InsertionSort(ByVal array As List(Of Integer)) As List(Of Integer)
        For i As Integer = 1 To array.Count - 1
            Dim key As Integer = array(i)
            Dim j As Integer = i - 1
            While j >= 0 AndAlso array(j) > key
                array(j + 1) = array(j)
                j -= 1
            End While
            array(j + 1) = key
        Next
        Return array
    End Function
End Module
