@extends('layout')

@section('title')
    Korean Library
@endsection

@section('content')
    Here is Korean
    <ul>
        @foreach($koreans as $korean)
            <li>{{ $korean }}</li>
        @endforeach
    </ul>
@endsection
